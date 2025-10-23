// Use express
const express = require("express");
const app = express();
// Use port
const port = 3000;

// Use middleware
app.use(express.json());

// Use routes in '/'
app.get("/", (req, res) => {
    res.send("Hello World!"); // Send response 
});

// Use server
app.listen(port, () => {
    console.log(`Example app listening in http://localhost:${port}`);
});
