let quantidade = Number(prompt("Quantos numeros deseja digitar? "));
let vetor1 = [quantidade];

for(let i=0 ; i<quantidade; i++) {
    vetor1[i] = Number(prompt("Digite um numero: "));

}

let vet = vetor1.map(function (vetor) {
    if(vetor <=10){
        return vetor * 2;
    } else {
        return vetor;
    }
});

alert(vet);
console.log(vet);