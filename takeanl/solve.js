const child_process = require('child_process');
const net = require('net');

var buffer = '';

conn = net.createConnection(9000, 'misc.chal.csaw.io');

conn.on('data', function(data) {
	stringData = data.toString();
	console.log(stringData);
	buffer += stringData;

	if (data.toString().includes('marked block: (')) {
		var width = /[0-9]+x[0-9]+/.exec(buffer)[0].split('x')[0];
		var x = /\([0-9]+/.exec(buffer)[0].replace('(', '');
		var y = /[0-9]+\)/.exec(buffer)[0].replace(')', '');
		console.log(`Parsed ${ width }, ${ x }, ${ y }`);

		buffer = '';

		var proc = child_process.spawnSync('./a.out', [width, x, y]);
		// var proc = child_process.spawn('echo', [width, x, y]);
		var answer = proc.stdout.toString();
		// proc.on('data', function(answer) {
		console.log(`Answer: ${ answer }`);
		conn.write(answer + '\n');

		// proc.on('error', function(err) {
		// 	console.log(err);
		// });
	}
});