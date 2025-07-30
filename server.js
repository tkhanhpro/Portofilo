const express = require('express');
const cors = require('cors');
const app = express();

app.use(cors());
app.use(express.json());

app.post('/api/contact', (req, res) => {
  const { name, email, message } = req.body;
  // Ở đây bạn có thể lưu vào database (MongoDB) hoặc gửi email (nodemailer)
  console.log('Received contact:', { name, email, message });
  res.status(200).json({ message: 'Contact message received!' });
});

app.listen(3000, () => {
  console.log('Server running on http://localhost:3000');
});
