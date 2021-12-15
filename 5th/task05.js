
class Node {
	constructor(str, tail) {
		this.str = str;
		this.tail = tail;
	}
}

function printValues(node) {
	console.log(node.str);
	if (node.tail == null) return;
	return printValues(node.tail);
}

function addTail(node, str) {
	node.tail = new Node(str, null);
}

function removeTail(node) {
	node.tail = null;
}

function addHead(head, str) {
	node = new Node(str, head);
	return node;
}

head = new Node("I", null);
console.log(head.str);

addTail(head, "am");
printValues(head);

head = addHead(head, "Hi,")
printValues(head);

