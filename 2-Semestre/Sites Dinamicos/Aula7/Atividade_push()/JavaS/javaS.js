let valor = document.querySelector("#id_valor");
let adicionar = document.querySelector("#id_adicionar");
let vetor = JSON.parse(localStorage.getItem("valores")) || [];                      // Recupera o vetor do localStorage ou inicializa como um array vazio
let historico = JSON.parse(localStorage.getItem("historico")) || [];                // Recupera o histórico do localStorage ou inicializa como um array vazio
let limpar = document.querySelector("#id_limpar");                                  // Função para limpar o histórico e o vetor (Função de auxílio temporaria)

let transformar = document.querySelector("#id_transformar");                          // Função para transformar o vetor (Função de auxílio temporaria)

const dolar = 5;
const euro = 5.5;



adicionar.addEventListener("click", function(event) {
    event.preventDefault();                                                         // Impede que a pagina atualize sozinha
    if(valor.value === "" || valor.value <= 0) {                                                        // Verifica se o campo está vazio
        alert("Insira um valor para continuar");
    } else {
        vetor.push(valor.value);                                                    // Adiciona o valor ao vetor
        localStorage.setItem("valores", JSON.stringify(vetor));                                   // Salva o vetor atualizado no localStorage
        historico.push({ valor: valor.value, data: new Date() });                   // Adiciona o valor e a data ao histórico
        localStorage.setItem("historico", JSON.stringify(historico));               // Salva o histórico atualizado no localStorage
        alert(`O valor ${valor.value} foi adicionado com sucesso`);                 // Exibe uma mensagem de sucesso
        document.querySelector("#id_vetor").textContent = `[${vetor.join(", ")}]`;  // Atualiza o conteúdo do elemento com o vetor atualizado

        // Atualiza o conteúdo do elemento com o histórico atualizado, formatando a data e o valor convertido em reais (Conteúdo não visto na aula)
        document.querySelector("#id_historico").textContent = historico.map(item =>`${new Date(item.data).toLocaleString("pt-BR")} -- Valor ${Number(item.valor).toLocaleString("pt-BR", { style: "currency", currency: "BRL" })} adicionado`).join("\n");
    }
});

limpar.addEventListener("click", function(event) {             // Função para limpar o histórico e o vetor (Função de auxílio temporaria)
    event.preventDefault();                                    // Impede que a pagina atualize sozinha
    vetor = [];                                                // Limpa o vetor
    historico = [];                                            // Limpa o histórico

    document.querySelector("#id_vetor").textContent = `[]`;    // Atualiza o conteúdo do elemento com o vetor vazio
    document.querySelector("#id_historico").textContent = `.`; // Atualiza o conteúdo do elemento com o histórico vazio

});

transformar.addEventListener("click", function(event) {         // Função para transformar o vetor (Função de auxílio temporaria)
    event.preventDefault();                                     // Impede que a pagina atualize sozinha
    let vetorConvert = [];
    const opcaoes = document.querySelector("#opcoes").value;    // Recupera o valor selecionado no select
    if(opcaoes === "opcao1") {
        vetorConvert = vetor.map(item => Number(item));         // Converte os valores do vetor para números
        
        vetorConvert = vetor.map(function (vet) {               // Função para iniciar conversão do vetor
        return vet * dolar;                                     // Converte os valores em dolar
        });
    }

    if(opcaoes === "opcao2") {
        vetorConvert = vetor.map(item => Number(item));         // Converte os valores do vetor para números
        
        vetorConvert = vetor.map(function (vet) {               // Função para iniciar conversão do vetor
        return vet * euro;                                     // Converte os valores em dolar
        });
    }
    document.querySelector("#vetorconvertido").textContent = `[${vetorConvert.join(", ")}]`;

});