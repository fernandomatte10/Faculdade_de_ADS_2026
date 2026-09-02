//let nome = document.getElementById("id_nome");
// let nome: cria uma variável chamada nome
// document: estou me referindo ao meu documento HTML
// querySelector: selecionar algo dentro do doc.HTML
// # sinalizar que é um id !
// . sinalizar que é uma class
// value serve para pegar o valor digitado

function vervalores() {

    let nome = document.querySelector("#id_nome");
    let idade = document.querySelector("#id_idade");
     dataNascimento = document.querySelector("#id_data_nascimento");

    console.log(nome.value);
    console.log(idade.value);
    console.log(dataNascimento.value);

}