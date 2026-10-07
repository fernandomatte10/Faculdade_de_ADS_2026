let nome = document.querySelector("#id_nome");
let inserir = document.querySelector("#id_inserir");
let alterar = document.querySelector("#id_alterar");
let buscar = document.querySelector("#id_buscar");
let excluir = document.querySelector("#id_excluir");

inserir.addEventListener("click", function(event) {
    event.preventDefault(); // Impede que a pagina atualize sozinha
    localStorage.setItem("nome", nome.value);
    alert(`O nome ${nome.value} foi inserido com sucesso`);

});