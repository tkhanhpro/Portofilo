<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>My VIP Portfolio</title>
  <script src="https://cdn.tailwindcss.com"></script>
  <script src="https://unpkg.com/react@18/umd/react.development.js"></script>
  <script src="https://unpkg.com/react-dom@18/umd/react-dom.development.js"></script>
  <script src="https://unpkg.com/@babel/standalone/babel.min.js"></script>
  <script src="https://unpkg.com/framer-motion/dist/framer-motion.js"></script>
  <script src="https://cdnjs.cloudflare.com/ajax/libs/gsap/3.12.2/gsap.min.js"></script>
  <script src="https://cdnjs.cloudflare.com/ajax/libs/gsap/3.12.2/ScrollTrigger.min.js"></script>
  <script src="https://cdn.jsdelivr.net/npm/particles.js@2.0.0/particles.min.js"></script>
  <style>
    body {
      background: linear-gradient(135deg, #1e3a8a, #4c1d95, #7c3aed);
      min-height: 100vh;
      font-family: 'Arial', sans-serif;
      color: #ffffff;
      transition: background 0.5s ease;
    }
    .glow {
      box-shadow: 0 0 20px rgba(124, 58, 237, 0.7);
      transition: all 0.3s ease;
    }
    .glow:hover {
      box-shadow: 0 0 30px rgba(124, 58, 237, 1);
      transform: scale(1.05);
    }
    .parallax {
      background-attachment: fixed;
      background-size: cover;
      background-position: center;
    }
    .tilt {
      transform-style: preserve-3d;
      transition: transform 0.3s ease;
    }
    #particles-js {
      position: absolute;
      width: 100%;
      height: 100%;
      z-index: 0;
    }
    .light-mode {
      background: linear-gradient(135deg, #e0e7ff, #f3e8ff, #ddd6fe);
      color: #1f2937;
    }
  </style>
</head>
<body>
  <div id="root"></div>
  <script type="text/babel">
    const { motion } = window.FramerMotion;
    const { gsap } = window;

    // Music Player Component
    function MusicPlayer() {
      const [isPlaying, setIsPlaying] = React.useState(false);
      const audioRef = React.useRef(new Audio('https://www.soundhelix.com/examples/mp3/SoundHelix-Song-1.mp3'));

      React.useEffect(() => {
        return () => audioRef.current.pause();
      }, []);

      const toggleMusic = () => {
        if (isPlaying) {
          audioRef.current.pause();
        } else {
          audioRef.current.play();
        }
        setIsPlaying(!isPlaying);
      };

      return (
        <motion.button
          whileHover={{ scale: 1.2 }}
          whileTap={{ scale: 0.9 }}
          onClick={toggleMusic}
          className="fixed bottom-4 right-4 p-3 bg-gradient-to-r from-pink-500 to-purple-500 rounded-full glow text-white"
        >
          {isPlaying ? 'Pause Music' : 'Play Music'}
        </motion.button>
      );
    }

    // Theme Toggle Component
    function ThemeToggle() {
      const [isDark, setIsDark] = React.useState(true);

      React.useEffect(() => {
        document.body.classList.toggle('light-mode', !isDark);
      }, [isDark]);

      return (
        <motion.button
          whileHover={{ scale: 1.2 }}
          whileTap={{ scale: 0.9 }}
          onClick={() => setIsDark(!isDark)}
          className="fixed top-4 right-4 p-3 bg-gradient-to-r from-cyan-500 to-purple-500 rounded-full glow text-white"
        >
          {isDark ? 'Light Mode' : 'Dark Mode'}
        </motion.button>
      );
    }

    // Navbar Component
    function Navbar() {
      React.useEffect(() => {
        gsap.fromTo(
          '.nav-item',
          { y: -20, opacity: 0 },
          { y: 0, opacity: 1, stagger: 0.2, duration: 0.8, ease: 'power3.out' }
        );
      }, []);

      return (
        <motion.nav
          initial={{ y: -100 }}
          animate={{ y: 0 }}
          transition={{ duration: 0.8, ease: 'easeOut' }}
          className="fixed top-0 w-full bg-gradient-to-r from-purple-900 to-indigo-900 p-4 shadow-lg z-10"
        >
          <div className="container mx-auto flex justify-between items-center">
            <h1 className="text-2xl font-bold text-white">My VIP Portfolio</h1>
            <div className="space-x-4">
              <a href="#about" className="nav-item text-white hover:text-purple-300 transition">About</a>
              <a href="#projects" className="nav-item text-white hover:text-purple-300 transition">Projects</a>
              <a href="#skills" className="nav-item text-white hover:text-purple-300 transition">Skills</a>
              <a href="#contact" className="nav-item text-white hover:text-purple-300 transition">Contact</a>
            </div>
          </div>
        </motion.nav>
      );
    }

    // About Component
    function About() {
      React.useEffect(() => {
        particlesJS('particles-js', {
          particles: {
            number: { value: 80, density: { enable: true, value_area: 800 } },
            color: { value: '#ffffff' },
            shape: { type: 'circle' },
            opacity: { value: 0.5, random: true },
            size: { value: 3, random: true },
            line_linked: { enable: true, distance: 150, color: '#ffffff', opacity: 0.4, width: 1 },
            move: { enable: true, speed: 6, direction: 'none', random: false }
          },
          interactivity: {
            detect_on: 'canvas',
            events: { onhover: { enable: true, mode: 'repulse' }, onclick: { enable: true, mode: 'push' } },
            modes: { repulse: { distance: 100, duration: 0.4 }, push: { particles_nb: 4 } }
          }
        });

        gsap.fromTo(
          '.about-text',
          { opacity: 0, y: 50 },
          { opacity: 1, y: 0, duration: 1.5, ease: 'power3.out', scrollTrigger: { trigger: '#about', start: 'top 80%' } }
        );
      }, []);

      return (
        <section id="about" className="min-h-screen flex items-center justify-center parallax relative" style={{ backgroundImage: "url('https://source.unsplash.com/random/1920x1080?galaxy')" }}>
          <div id="particles-js" className="absolute inset-0"></div>
          <motion.div
            initial={{ opacity: 0, y: 50 }}
            whileInView={{ opacity: 1, y: 0 }}
            transition={{ duration: 1 }}
            className="about-text text-center max-w-2xl p-6 bg-gray-900 bg-opacity-80 rounded-lg glow relative z-10"
          >
            <h2 className="text-4xl font-bold mb-4 bg-clip-text text-transparent bg-gradient-to-r from-pink-500 to-purple-500">About Me</h2>
            <p className="text-lg">
              I'm a full-stack developer creating world-class web experiences. With expertise in React, Node.js, and cutting-edge animations, I build stunning, interactive applications that captivate users.
            </p>
          </motion.div>
        </section>
      );
    }

    // Projects Component
    function Projects() {
      const projects = [
        { title: "Project 1", desc: "An e-commerce platform with real-time payment integration.", link: "#" },
        { title: "Project 2", desc: "A 3D interactive portfolio with WebGL effects.", link: "#" },
        { title: "Project 3", desc: "A real-time dashboard with live data visualization.", link: "#" },
      ];

      React.useEffect(() => {
        gsap.utils.toArray('.project-card').forEach((card, index) => {
          gsap.fromTo(
            card,
            { opacity: 0, scale: 0.8 },
            { opacity: 1, scale: 1, duration: 0.8, delay: index * 0.2, ease: 'power3.out', scrollTrigger: { trigger: card, start: 'top 80%' } }
          );

          card.addEventListener('mousemove', (e) => {
            const rect = card.getBoundingClientRect();
            const x = e.clientX - rect.left - rect.width / 2;
            const y = e.clientY - rect.top - rect.height / 2;
            gsap.to(card, { rotationY: x / 50, rotationX: -y / 50, duration: 0.3 });
          });
          card.addEventListener('mouseleave', () => {
            gsap.to(card, { rotationY: 0, rotationX: 0, duration: 0.3 });
          });
        });
      }, []);

      return (
        <section id="projects" className="min-h-screen py-16 bg-gradient-to-b from-indigo-900 to-gray-900">
          <div className="container mx-auto">
            <h2 className="text-4xl font-bold text-center mb-12 bg-clip-text text-transparent bg-gradient-to-r from-cyan-400 to-purple-500">My Projects</h2>
            <div className="grid grid-cols-1 md:grid-cols-3 gap-8">
              {projects.map((project, index) => (
                <motion.div
                  key={index}
                  className="project-card p-6 bg-gray-800 rounded-lg glow tilt"
                >
                  <h3 className="text-2xl font-semibold mb-2">{project.title}</h3>
                  <p className="mb-4">{project.desc}</p>
                  <a href={project.link} className="text-purple-400 hover:text-purple-200">View Project</a>
                </motion.div>
              ))}
            </div>
          </div>
        </section>
      );
    }

    // Skills Component
    function Skills() {
      const skills = ["React", "Node.js", "Tailwind CSS", "Framer Motion", "GSAP", "MongoDB"];

      React.useEffect(() => {
        gsap.utils.toArray('.skill-card').forEach((card, index) => {
          gsap.fromTo(
            card,
            { opacity: 0, y: 20 },
            { opacity: 1, y: 0, duration: 0.5, delay: index * 0.1, ease: 'power3.out', scrollTrigger: { trigger: card, start: 'top 80%' } }
          );
        });
      }, []);

      return (
        <section id="skills" className="min-h-screen py-16 bg-gradient-to-b from-gray-900 to-black">
          <div className="container mx-auto">
            <h2 className="text-4xl font-bold text-center mb-12 bg-clip-text text-transparent bg-gradient-to-r from-pink-400 to-purple-400">My Skills</h2>
            <div className="grid grid-cols-2 md:grid-cols-3 gap-4">
              {skills.map((skill, index) => (
                <motion.div
                  key={index}
                  whileHover={{ scale: 1.1, rotate: 5 }}
                  className="skill-card p-4 bg-purple-800 rounded-lg text-center glow"
                >
                  {skill}
                </motion.div>
              ))}
            </div>
          </div>
        </section>
      );
    }

    // Contact Component
    function Contact() {
      const [formData, setFormData] = React.useState({ name: '', email: '', message: '' });
      const [status, setStatus] = React.useState('');

      const handleChange = (e) => {
        setFormData({ ...formData, [e.target.name]: e.target.value });
      };

      const handleSubmit = async (e) => {
        e.preventDefault();
        try {
          // Simulate API call with JSONPlaceholder
          const response = await fetch('https://jsonplaceholder.typicode.com/posts', {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify(formData),
          });
          if (response.ok) {
            setStatus('Message sent successfully!');
            setFormData({ name: '', email: '', message: '' });
          } else {
            setStatus('Failed to send message.');
          }
        } catch (error) {
          setStatus('Error: ' + error.message);
        }
      };

      return (
        <section id="contact" className="min-h-screen py-16 bg-gradient-to-b from-black to-indigo-900 flex items-center justify-center">
          <motion.div
            initial={{ opacity: 0, y: 50 }}
            whileInView={{ opacity: 1, y: 0 }}
            transition={{ duration: 1 }}
            className="max-w-lg w-full p-6 bg-gray-900 bg-opacity-80 rounded-lg glow"
          >
            <h2 className="text-4xl font-bold mb-6 text-center bg-clip-text text-transparent bg-gradient-to-r from-cyan-400 to-pink-500">Contact Me</h2>
            <div>
              <div className="mb-4">
                <label className="block text-sm mb-2">Name</label>
                <input
                  type="text"
                  name="name"
                  value={formData.name}
                  onChange={handleChange}
                  className="w-full p-3 bg-gray-800 rounded border border-purple-500 focus:outline-none focus:border-purple-300"
                />
              </div>
              <div className="mb-4">
                <label className="block text-sm mb-2">Email</label>
                <input
                  type="email"
                  name="email"
                  value={formData.email}
                  onChange={handleChange}
                  className="w-full p-3 bg-gray-800 rounded border border-purple-500 focus:outline-none focus:border-purple-300"
                />
              </div>
              <div className="mb-4">
                <label className="block text-sm mb-2">Message</label>
                <textarea
                  name="message"
                  value={formData.message}
                  onChange={handleChange}
                  className="w-full p-3 bg-gray-800 rounded border border-purple-500 focus:outline-none focus:border-purple-300 h-32"
                ></textarea>
              </div>
              <motion.button
                whileHover={{ scale: 1.1 }}
                whileTap={{ scale: 0.9 }}
                onClick={handleSubmit}
                className="w-full p-3 bg-gradient-to-r from-purple-500 to-pink-500 rounded-lg text-white font-bold glow"
              >
                Send Message
              </motion.button>
              {status && <p className="mt-4 text-center">{status}</p>}
            </div>
          </motion.div>
        </section>
      );
    }

    // App Component
    function App() {
      return (
        <main>
          <Navbar />
          <ThemeToggle />
          <MusicPlayer />
          <About />
          <Projects />
          <Skills />
          <Contact />
        </main>
      );
    }

    // Render App
    ReactDOM.render(<App />, document.getElementById('root'));
  </script>
</body>
</html>
