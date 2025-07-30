const express = require('express');
const path = require('path');
const app = express();
const port = process.env.PORT || 3000;

// Serve static files from frontend build
app.use(express.static(path.join(__dirname, '../frontend/build')));

// Route for homepage
app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, '../frontend/build', 'index.html'));
});

// Route for API documentation
app.get('/apiDocs', (req, res) => {
  res.sendFile(path.join(__dirname, 'views', 'apiDocs.html'));
});

app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
});
