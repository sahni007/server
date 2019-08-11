const express = require('express');
const http =require('http');

const app = express();

app.get('/auto',(request,response)=>{
	
	console.log("Api Hitted...");
	response.send({
		
						"ID": "Smart Grid Detector",
						"SortAs": "SGDL",
						"GlossTerm": "Standard Generalized Markup Language",
						"Acronym": "SGD-UCM",
						"Abbrev": "ISO 8879:1986",
						
	});
	
})

app.listen(3000, ()=>{
	console.log("Hello WORLD....");
});