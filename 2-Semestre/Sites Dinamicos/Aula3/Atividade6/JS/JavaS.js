let n1 = Number(prompt("Digite uma nota: "));
let n2 = Number(prompt("Digite outra nota: "));

let media = (n1 + n2) / 2;

if(media > 6.9) {
    alert(`Media ${media}, aprovado!\n`);
    //console.log(`Media ${media}, aprovado!\n`);
} else {
    alert(`Media ${media}, reprovado!\n`);
    //console.log(`Media ${media}, reprovado!\n`);
}