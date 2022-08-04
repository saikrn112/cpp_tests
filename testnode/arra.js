"use strict";
let user = {
    name: "Ramana",
    surName: "PinnamaRaju",
    get fullName() {
        return `...`;
    },
    set fullName(value) {
        [this.name, this.surname] = value.split(" ");
    },
};

user.fullName = "Test"

function User(name, age) {
    this.name = name;
    this.age = age;
};

let john = new User("John", 25);


let animal = {
  eats: true,
  walk() {
    console.log("animal walk");
  }
};

let rabbit = {
  jumps: true,
  __proto__: animal,
  walk() {
      __proto__.walk();
    console.log("rabbit walks and jumps");
  },
};

console.log(animal.__proto__);
// walk is taken from the prototype
rabbit.walk(); // Animal walk
