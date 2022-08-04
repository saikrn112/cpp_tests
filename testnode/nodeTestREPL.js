console.log('test')
console.info('test')
console.__defineGetter__
global.perf_hooks
let fruits = ["Raman", "Apple", "hello"];
for(fruit of fruits){
  console.info(fruit);
}

const express = require('express');
const app = express();
app.get('/', (req,res) => {
    res.send('Hi!')
    });
    
    
    app.listen(3000, ()=> console.log('Server read'));
    
    process.on('SIGTERM', () => {
        server.close(() => {
                  console.log('Process terminated')
                      })
                    })
                    