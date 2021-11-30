
class MyClass {
	constructor (key, str) {
		this.key = key;
		this.str = str;
	}

	printStatus () {
		console.log(this.key);
		console.log(this.str);
	}
}

myObject = new MyClass(101, "I am a pen.");
myObject.printStatus();

