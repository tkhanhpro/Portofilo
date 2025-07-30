import { motion } from 'framer-motion';
import { useEffect, useState } from 'react';

function Bio({ data }) {
  const [displayedText, setDisplayedText] = useState('');
  const [index, setIndex] = useState(0);

  useEffect(() => {
    if (index < data.name.length) {
      const timeout = setTimeout(() => {
        setDisplayedText((prev) => prev + data.name[index]);
        setIndex(index + 1);
      }, 100);
      return () => clearTimeout(timeout);
    }
  }, [index, data.name]);

  return (
    <div className="text-center mb-8">
      <motion.h1
        className="text-3xl md:text-4xl font-bold text-white"
        initial={{ opacity: 0 }}
        animate={{ opacity: 1 }}
        transition={{ delay: 0.5, duration: 0.8 }}
      >
        {displayedText}
        <span className="animate-pulse">|</span>
      </motion.h1>
      <motion.h2
        className="text-xl md:text-2xl text-blue-300 mt-2"
        initial={{ opacity: 0 }}
        animate={{ opacity: 1 }}
        transition={{ delay: 0.7, duration: 0.8 }}
      >
        {data.title}
      </motion.h2>
      <motion.p
        className="text-gray-300 mt-4 max-w-md mx-auto"
        initial={{ opacity: 0 }}
        animate={{ opacity: 1 }}
        transition={{ delay: 0.9, duration: 0.8 }}
      >
        {data.bio}
      </motion.p>
    </div>
  );
}

export default Bio;
