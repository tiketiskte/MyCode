/** @type {import('tailwindcss').Config} */
export default {
  content: ['./index.html', './src/**/*.{js,ts,jsx,tsx}'],
  theme: {
    extend: {
      colors: {
        primary: {
          DEFAULT: '#07C160',
          dark: '#06AD56',
        },
        income: '#16A34A',
        expense: '#FA5151',
        surface: '#F7F8FA',
        card: '#FFFFFF',
        text: {
          primary: '#191919',
          secondary: '#888888',
        },
      },
      maxWidth: {
        app: '430px',
      },
      boxShadow: {
        card: '0 2px 12px rgba(0, 0, 0, 0.06)',
      },
      backgroundImage: {
        'gradient-primary': 'linear-gradient(135deg, #07C160 0%, #10B981 100%)',
      },
      keyframes: {
        'slide-up': {
          from: { transform: 'translateY(100%)' },
          to: { transform: 'translateY(0)' },
        },
      },
      animation: {
        'slide-up': 'slide-up 0.25s ease-out',
      },
    },
  },
  plugins: [],
};
