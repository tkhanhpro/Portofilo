import { motion } from 'framer-motion';
import Avatar from './components/Avatar';
import Bio from './components/Bio';
import Skills from './components/Skills';
import SocialLinks from './components/SocialLinks';
import { profileData } from './data';

function App() {
  return (
    <div className="min-h-screen bg-gradient-to-br from-gray-900 to-blue-900 flex items-center justify-center p-4">
      <motion.div 
        className="max-w-2xl w-full bg-white/10 backdrop-blur-lg rounded-xl shadow-2xl p-8"
        initial={{ opacity: 0, y: 50 }}
        animate={{ opacity: 1, y: 0 }}
        transition={{ duration: 0.8, ease: 'easeOut' }}
      >
        <Avatar />
        <Bio data={profileData} />
        <Skills skills={profileData.skills} />
        <SocialLinks links={profileData.socialLinks} />
        <motion.a
          href="/cv.pdf"
          className="block mt-8 text-center bg-blue-500 text-white py-3 px-6 rounded-lg hover:bg-blue-600 transition duration-300"
          whileHover={{ scale: 1.05 }}
          whileTap={{ scale: 0.95 }}
        >
          Download CV
        </motion.a>
      </motion.div>
    </div>
  );
}

export default App;
