import { motion } from 'framer-motion';

function SocialLinks({ links }) {
  return (
    <div className="flex justify-center gap-4 mb-8">
      {links.map((link, index) => (
        <motion.a
          key={link.name}
          href={link.url}
          target="_blank"
          rel="noopener noreferrer"
          className="text-white hover:text-blue-300 transition-colors duration-300"
          initial={{ opacity: 0, y: 20 }}
          animate={{ opacity: 1, y: 0 }}
          transition={{ delay: index * 0.2, duration: 0.5 }}
          whileHover={{ scale: 1.2, rotate: 5 }}
        >
          <i className={link.icon}></i>
        </motion.a>
      ))}
    </div>
  );
}

export default SocialLinks;
