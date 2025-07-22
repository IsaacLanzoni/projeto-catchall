const express = require('express');
const bodyParser = require('body-parser');
const cors = require('cors');

const app = express();
const PORT = 3000;

app.use(bodyParser.json());
app.use(cors());

app.post('/dados', (req, res) => {
    console.log('JSON recebido:', req.body);
    res.json({mensagem: 'Dados recebidos corretamente!'});
});

//Servidor é iniciado

app.listen(PORT, () => {
    console.log(`API rodando em http://localhost:${PORT}`);
});