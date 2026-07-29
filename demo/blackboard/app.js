(function () {
  "use strict";

  const CHALK_COLORS = [
    { name: "白", value: "#f5f5f0" },
    { name: "黄", value: "#fde68a" },
    { name: "粉", value: "#f9a8d4" },
    { name: "绿", value: "#86efac" },
    { name: "蓝", value: "#93c5fd" },
    { name: "橙", value: "#fdba74" },
  ];


  const canvas = document.getElementById("board");
  const ctx = canvas.getContext("2d");
  const brushSizeInput = document.getElementById("brushSize");
  const brushSizeLabel = document.getElementById("brushSizeLabel");
  const colorPalette = document.getElementById("colorPalette");
  const eraserBtn = document.getElementById("eraserBtn");
  const undoBtn = document.getElementById("undoBtn");
  const clearBtn = document.getElementById("clearBtn");
  const exportBtn = document.getElementById("exportBtn");

  let isDrawing = false;
  let isEraser = false;
  let currentColor = CHALK_COLORS[0].value;
  let lastX = 0;
  let lastY = 0;
  let undoStack = [];

  function resizeCanvas() {
    const rect = canvas.getBoundingClientRect();
    const dpr = window.devicePixelRatio || 1;
    const lastState = undoStack.length ? undoStack[undoStack.length - 1] : null;

    canvas.width = Math.floor(rect.width * dpr);
    canvas.height = Math.floor(rect.height * dpr);
    ctx.setTransform(dpr, 0, 0, dpr, 0, 0);

    if (lastState) {
      const img = new Image();
      img.onload = () => {
        fillBoardBackground();
        ctx.drawImage(img, 0, 0, rect.width, rect.height);
      };
      img.src = lastState;
    } else {
      fillBoardBackground();
    }
  }

  function fillBoardBackground() {
    const w = canvas.width / (window.devicePixelRatio || 1);
    const h = canvas.height / (window.devicePixelRatio || 1);
    const gradient = ctx.createLinearGradient(0, 0, w, h);
    gradient.addColorStop(0, "#1e4534");
    gradient.addColorStop(0.5, "#1a3d2e");
    gradient.addColorStop(1, "#153028");
    ctx.fillStyle = gradient;
    ctx.fillRect(0, 0, w, h);
  }

  function drawChalkTexture() {
    const w = canvas.width / (window.devicePixelRatio || 1);
    const h = canvas.height / (window.devicePixelRatio || 1);
    const imageData = ctx.getImageData(0, 0, canvas.width, canvas.height);
    const data = imageData.data;

    for (let i = 0; i < data.length; i += 4) {
      const noise = (Math.random() - 0.5) * 8;
      data[i] = Math.min(255, Math.max(0, data[i] + noise));
      data[i + 1] = Math.min(255, Math.max(0, data[i + 1] + noise));
      data[i + 2] = Math.min(255, Math.max(0, data[i + 2] + noise));
    }

    ctx.putImageData(imageData, 0, 0);
  }

  function initBoard() {
    fillBoardBackground();
    drawChalkTexture();
    saveState();
  }

  function saveState() {
    if (undoStack.length >= MAX_UNDO) {
      undoStack.shift();
    }
    undoStack.push(canvas.toDataURL("image/png"));
  }

  function restoreFromUndo() {
    if (undoStack.length === 0) return;

    const dataUrl = undoStack[undoStack.length - 1];
    const img = new Image();
    img.onload = () => {
      const w = canvas.width / (window.devicePixelRatio || 1);
      const h = canvas.height / (window.devicePixelRatio || 1);
      fillBoardBackground();
      ctx.drawImage(img, 0, 0, w, h);
    };
    img.src = dataUrl;
  }

  function getPointerPos(e) {
    const rect = canvas.getBoundingClientRect();
    const clientX = e.touches ? e.touches[0].clientX : e.clientX;
    const clientY = e.touches ? e.touches[0].clientY : e.clientY;
    return {
      x: clientX - rect.left,
      y: clientY - rect.top,
    };
  }

  function startDraw(e) {
    e.preventDefault();
    isDrawing = true;
    const pos = getPointerPos(e);
    lastX = pos.x;
    lastY = pos.y;

    ctx.beginPath();
    ctx.moveTo(lastX, lastY);
    ctx.lineTo(lastX + 0.1, lastY + 0.1);
    ctx.stroke();
  }

  function draw(e) {
    if (!isDrawing) return;
    e.preventDefault();

    const pos = getPointerPos(e);
    const size = Number(brushSizeInput.value);

    ctx.lineCap = "round";
    ctx.lineJoin = "round";
    ctx.lineWidth = size;

    if (isEraser) {
      ctx.globalCompositeOperation = "destination-out";
      ctx.strokeStyle = "rgba(0,0,0,1)";
    } else {
      ctx.globalCompositeOperation = "source-over";
      ctx.strokeStyle = currentColor;
      ctx.shadowColor = currentColor;
      ctx.shadowBlur = size * 0.35;
    }

    ctx.beginPath();
    ctx.moveTo(lastX, lastY);
    ctx.lineTo(pos.x, pos.y);
    ctx.stroke();

    ctx.shadowBlur = 0;
    lastX = pos.x;
    lastY = pos.y;
  }

  function endDraw() {
    if (!isDrawing) return;
    isDrawing = false;
    ctx.globalCompositeOperation = "source-over";
    ctx.shadowBlur = 0;
    saveState();
  }

  function buildColorPalette() {
    CHALK_COLORS.forEach((color, index) => {
      const btn = document.createElement("button");
      btn.type = "button";
      btn.className = "color-btn" + (index === 0 ? " active" : "");
      btn.style.backgroundColor = color.value;
      btn.title = color.name + "色粉笔";
      btn.dataset.color = color.value;
      btn.addEventListener("click", () => {
        isEraser = false;
        currentColor = color.value;
        canvas.classList.remove("eraser-mode");
        eraserBtn.classList.remove("active");
        document.querySelectorAll(".color-btn").forEach((b) => b.classList.remove("active"));
        btn.classList.add("active");
      });
      colorPalette.appendChild(btn);
    });
  }

  function undo() {
    if (undoStack.length <= 1) return;
    undoStack.pop();
    restoreFromUndo();
  }

  function clearBoard() {
    if (!confirm("确定要清空黑板吗？")) return;
    undoStack = [];
    initBoard();
  }

  function exportImage() {
    const link = document.createElement("a");
    const timestamp = new Date().toISOString().slice(0, 19).replace(/[T:]/g, "-");
    link.download = `blackboard-${timestamp}.png`;
    link.href = canvas.toDataURL("image/png");
    link.click();
  }

  brushSizeInput.addEventListener("input", () => {
    brushSizeLabel.textContent = `${brushSizeInput.value}px`;
  });

  eraserBtn.addEventListener("click", () => {
    isEraser = !isEraser;
    eraserBtn.classList.toggle("active", isEraser);
    canvas.classList.toggle("eraser-mode", isEraser);
    if (isEraser) {
      document.querySelectorAll(".color-btn").forEach((b) => b.classList.remove("active"));
    } else {
      const active = [...document.querySelectorAll(".color-btn")].find(
        (b) => b.dataset.color === currentColor
      );
      if (active) active.classList.add("active");
    }
  });

  undoBtn.addEventListener("click", undo);
  clearBtn.addEventListener("click", clearBoard);
  exportBtn.addEventListener("click", exportImage);

  canvas.addEventListener("mousedown", startDraw);
  canvas.addEventListener("mousemove", draw);
  canvas.addEventListener("mouseup", endDraw);
  canvas.addEventListener("mouseleave", endDraw);

  canvas.addEventListener("touchstart", startDraw, { passive: false });
  canvas.addEventListener("touchmove", draw, { passive: false });
  canvas.addEventListener("touchend", endDraw);
  canvas.addEventListener("touchcancel", endDraw);

  window.addEventListener("resize", resizeCanvas);

  buildColorPalette();
  resizeCanvas();
  initBoard();
})();
