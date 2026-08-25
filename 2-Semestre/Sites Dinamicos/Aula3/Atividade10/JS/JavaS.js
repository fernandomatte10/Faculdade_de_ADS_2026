let n1 = Number(prompt("Digite um numero: "));
let n2 = Number(prompt("Digite outro numero: "));
let n3 = Number(prompt("Digite o último numero: "));

let maior = n1;

if(n2 > maior) {
    maior = n2;
} else if (n3 > maior) {
    maior = n3;
}

console.log(`Maior numero: ${maior}\n`);
alert(`Maior numero: ${maior}\n`);