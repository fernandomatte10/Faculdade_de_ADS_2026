let formulario = document.querySelector("#id_form");
let nome = document.querySelector("#id_nome");
let botao = document.querySelector("#id_botao");

// addEventListener funciona como uma escuta, fica esperando um evento
// Submit e um evento de envio

/*
formulario.addEventListener("submit",function(event){

    event.preventDefault(); // previne o envio do formulario
    console.log("Formulario enviado");

});
*/

// dbclick e um evento de clique duplo
botao.addEventListener("dblclick",function(){

    console.log("Salve");

});

nome.addEventListener("input",function(event){
    event.preventDefault();
    console.clear();
    console.log("Digitando...");
});

//document pega o documento inteiro
//keydown pega a tecla precionada
document.addEventListener("keydown",function(event){
    console.log(event.key);

    if(event.key === "Enter"){
        alert("Você precionou a tecla Enter");
    }
});
