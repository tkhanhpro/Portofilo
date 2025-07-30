import { motion } from 'framer-motion';

function Avatar() {
  return (
    <motion.div
      className="flex justify-center mb-6"
      initial={{ scale: 0 }}
      animate={{ scale: 1 }}
      transition={{ duration: 0.6, ease: 'easeOut' }}
    >
      <motion.div
        className="w-32 h-32 rounded-full overflow-hidden shadow-lg hover:shadow-blue-500/50 transition-shadow duration-300"
        whileHover={{ scale: 1.1 }}
      >
        <img
          src="https://via.placeholder.com/150"
          alt="Profile"
          className="w-full h-full object-cover"
        />
      </motion.div>
    </motion.div>
  );
}

export default Avatar;
