from PIL import Image
from torch.utils.tensorboard import SummaryWriter
from torchvision import transforms

img_path = "dataset/train/ants_image/0013035.jpg"
img = Image.open(img_path)

writer = SummaryWriter("logs")

tensor_transforms = transforms.ToTensor()
tensor_image = tensor_transforms(img)
writer.add_image("pic", tensor_image)
writer.close()
print(tensor_image)