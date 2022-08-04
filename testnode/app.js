/*
const http = require('http');

const hostname = '127.0.0.1';
const port = 3000;

const server = http.createServer((req,res) => {
    console.log(req);
    console.log(res);
    res.statusCode = 200;
    res.setHeader('Content-Type', 'text/plain');
    res.end('Hello World');
 });

server.listen(port,hostname, () => {
    console.log(`Server running at http://${hostname}:${port}/`);
 });
*/

let user = 'John', age = 25, message = 'Hello';
console.time('Getting Data');
console.info(message);
console.info(typeof(prompt));
console.timeEnd('Getting Data');
console.info('Program Ended');
console.info( !! (1 | 2));
console.info( false || true || undefined || null)
console.info( "" || ("" && "Asynchronous") || 1 || "well");
console.info( 3 && 1);

let funcName = function name(from="1", text)
{
    text = (text === undefined) ? "This is text not given" : text;
    return;
    console.info(`${from} is from`);
    console.info(`${text} is text`);
    console.info("First function");
    return 1 + '1';
}
let func2 = function ()
{
    return 1 + '1';
}

console.info(funcName("FROM","TEXT"));
console.info(funcName + "From");
console.info(funcName + func2);

for(let i = 1; i<3; i++) console.log(i);

let userObject = { name: "Ramana", age: "24", life: "existential crisis"};

console.info("life1" in userObject);

for (key in userObject)
{
    console.info(key + " " + userObject[key]);
}

delete userObject.life;
console.info("now life doesnt exist in " +  userObject["name"]);

for (key in userObject)
{
    console.info(key + " " + userObject[key]);
}

let nonExistingUser = {};
console.info(nonExistingUser.address && nonExistingUser.address.street);

let id = Symbol("This is a symbol");
let id2 = Symbol("This is a symbol");
console.info(id.description);

userObject[id] = 12;
console.info(userObject[id]);
console.info(userObject[id2]);
for (key in userObject){
    console.info(key + ":" + userObject[key]);
}
console.info(userObject[Symbol.for("This is a symbol")]);
userObject[Symbol.for("This is a symbol")] = "this is berk";
console.info(userObject[Symbol.for("This is a symbol")]);
console.info(Symbol.keyFor(Symbol.for("This is a symbol")));
console.info(Object.getOwnPropertySymbols(userObject));
console.info(Reflect.ownKeys(userObject));
console.info("This is small".toUpperCase());
console.info(1234.023.toString());
console.info(parseFloat("a1.234a"));

let guestList = `Guests:
* John
* Pete
* RamZ
* ramana `;

console.info(guestList);

console.info("\u{1F60D}".length);
console.info(guestList.charAt(3));

let fruits = ["Apple", "Orange", "Pear"];
for (let i of fruits){
    console.info(i);
}
console.info(fruits.valueOf());
process.argv.forEach((val,index)=>{
    console.log(`${index}:${val}`)
})

console.log('%o',Number);
console.count('Hello');
console.count('Hello');
console.count('Hello');
console.count('Hello');

const doSomething = () => console.log('test')
const measureDoingSomething = (func) => {
    console.time('doSomething()')
    func()
    console.timeEnd('doSomething()')
}
measureDoingSomething(doSomething)
console.log('\x1b[33m%s\x1b[0m', 'hi!')

/*
const ProgressBar = require('progress')

const bar = new ProgressBar(':bar', { total: 10 })
const timer = setInterval(() => {
  bar.tick()
  if (bar.complete) {
    clearInterval(timer)
  }
}, 100)

const _ = require('lodash');
console.info(_);
*/

const bar = () => console.log('bar');
const baz = () => console.log('baz');
const foo = () => {
    baz();
    console.log('foo');
    setTimeout(bar,1000);
};

measureDoingSomething(foo);

let done = true;
const isItDoneYet = new Promise((resolve,reject) => {
    if (done) {
        const workDone = 'Here is the thing I built';
        resolve(workDone);
    } else {
        const why = 'Still working on something else';
        reject(why);
    }
});

const checkIfItsDone = () => {
    isItDoneYet
        .then(ok => {
            console.log(ok)
        })
        .catch(err => {
            console.log(err)
        })
}
checkIfItsDone()

/* Async/ Await extension of Promises */
const doSomethingAsync = () => {
  return new Promise(resolve => {
    setTimeout(() => resolve('I did something'), 3000)
  })
}

const doSomethingAsyncAwait = async () => {
  console.log(await doSomethingAsync())
}

console.log('Before')
doSomethingAsyncAwait()
console.log('After')

const promiseToDoSomething = () => {
  return new Promise(resolve => {
    setTimeout(() => resolve('I did something'), 10000)
  })
}

const watchOverSomeoneDoingSomething = async () => {
  const something = await promiseToDoSomething()
  return something + '\nand I watched'
}

const watchOverSomeoneWatchingSomeoneDoingSomething = async () => {
  const something = await watchOverSomeoneDoingSomething()
  return something + '\nand I watched as well'
}

watchOverSomeoneWatchingSomeoneDoingSomething().then(res => {
  console.log(res)
})
