var express = require('express')

var app = express();
app.use(express.static('public'));

app.get('/', function(req, res){


    res.send('go to public!');
}
)

var server = app.listen(8080);
