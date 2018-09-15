const algebra = require('algebra.js');
const net = require('net');

conn = net.createConnection(9002, 'misc.chal.csaw.io');

conn.on('data', function(data) {
	var lines = data.toString().split('\n');
	for (var i=0; i<lines.length; i++) {
		console.log(lines[i]);
		if (lines[i].includes('=')) {
			var expressions = lines[i].split('=');
			console.log(`expr1: ${ expressions[0] }`)
			console.log(`expr2: ${ expressions[1] }`)
			var expr1 = new algebra.parse(expressions[0]);
			var expr2 = new algebra.parse(expressions[1]);
			var equation = new algebra.Equation(expr1, expr2);
			// This is insanely insecure, don't tell anyone I did this or I'll be unemployable
			var answer = eval(equation.solveFor('X').toString()).toString();
			console.log(`Answer: ${ answer }`);
			conn.write(answer + '\n');
		}
	}
});