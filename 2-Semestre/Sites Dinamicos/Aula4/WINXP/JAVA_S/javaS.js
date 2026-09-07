// let nome = document.getElementById("id_nome");
// let nome: cria uma variável chamada nome
// document: estou me referindo ao meu documento HTML
// querySelector: selecionar algo dentro do doc.HTML
// # sinalizar que é um id !
// . sinalizar que é uma class
// value serve para pegar o valor digitado

function login() {

    let user = document.querySelector("#id_username");
    let password = document.querySelector("#id_password");

    if (user.value === "FernandoMatte" && password.value === "123456789") {
        alert("Login realizado com sucesso!");
    } else {
        alert("Nome de usuário ou senha incorretos.");
    }
}