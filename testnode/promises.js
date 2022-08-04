/* 
const ret = new Promise((resolve, reject) => {
  setTimeout(() => reject("result"), 2000)
})

const ret1 = ret.finally(() => console.log("Promise ready"))
const ret2 = ret1.then(result => console.log(result)); // <-- .then handles the result
const ret3 = ret2.catch(reject => console.log(reject));

if ( ret1 == ret ) {
    console.log('ret and ret1 are same')
} else {
    console.log('they aren\'t');
}
*/

new Promise((resolve,reject) => {
    throw new Error("Whoops!");
}).catch(function(error) { 
    console.error("The error is handled, continue normally")
}).then(() => console.info("Next successful handler runs"))
 // .then(null, () => console.info("in the catch block"));


 const retPromis = new Promise(function(resolve, reject) {
  setTimeout(() => {
    reject(new Error("Whoops!"));
  }, 1000);
}).catch(() => "this is berk");

async function f() {

  let promise = new Promise((resolve, reject) => {
    setTimeout(() => resolve("done!"), 1000)
  });

  let result = await promise; // wait until the promise resolves (*)

  console.info(result); // "done!"
  return result;
};

async function ferror() {
    await Promise.reject(new Error("Whoops!"));
}
ferror().catch(res => console.log(res));;
