// const crypto = require('crypto');

// function registrarUsuario (email, senha) {

//     const senhaHash = crypto.createHash('sha256').update(senha).digest('hex');

//     bancoDeDados.query(
//         'INSERIR INTO usuarios (email, senha) VALUE (?, ?)',
//         [email, senhaHash]
//     );

//     return "Cadastro realizado com sucesso!";
// }



// function registrarUsuarioSeguro(email, senhaPlana) {
//     const salt = crypto.randomBytes(16).toString('hex');

//     crypto.scrypt(senhaPlana, salt, 64, (err, derivedKey) => {
//         if (err) throw err;

//         const senhaHash = derivedKey.toString('hex');

//         const registroFinal = `${salt}:${senhaHash}`
//         bancoDeDados.query(
//             'INSERT INTO usuarios (email, senha) VALUES (?, ?)',
//             [email, registroFinal]
//         );
//     });
// }