//Método usando apenas JS

/*
function avisarjs(n1 , n2){
    media=(n1 + n2) / 2;

    return media;
}

let num1 = Number(prompt("Digite um numero: "));
let num2 = Number(prompt("Digite outro numero: "));
let mediaf=0;

alert(`Média ${mediaf = avisarjs(num1, num2)}`);
console.log(`Média ${mediaf = avisarjs(num1, num2)}`);
*/


//Método usando HTML + JS por meio de botões
function mediafinal(){

    let nume1=parseFloat(document.querySelector(".numer1").value);
    let nume2=parseFloat(document.querySelector(".numer2").value);

    let mediaf=(nume1+nume2) / 2;
    alert(`Media dos numeros: ${mediaf}`);

}
