const express = require('express');

let app = express();

app.use(express.static(__dirname + '/publicTest'));
app.use(express.static(__dirname));


/* can you see this */

app.get('/', (req,res) => {
    res.send('Hello Express');
});

app.listen(process.env.PORT || 3000);
