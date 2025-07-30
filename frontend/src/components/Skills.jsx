import { motion } from 'framer-motion';

function Skills({ skills }) {
  return (
    <div className="mb-8">
      <h3 className="text-xl font-semibold text-white mb-4 text-center">Skills</h3>
      <div className="grid grid-cols-2 md:grid-cols-3 gap-4">
        {skills.map((skill, index) => (
          <motion.div
            key={skill}
            className="bg-blue-500/20 text-white text-center py-2 px-4 rounded-lg"
            initial={{ opacity: 0, y: 20 }}
            animate={{ opacity: 1, y: 0 }}
            transition={{ delay: index * 0.1, duration: 0.5 }}
            whileHover={{ scale: 1.05, backgroundColor: 'rgba(59, 130, 246, 0.4)' }}
          >
            {skill}
          </motion.div>
        ))}
      </div>
    </div>
  );
}

export default Skills;
