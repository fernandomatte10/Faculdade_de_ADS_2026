const produtos = ["Caderno", "Mochila", "Caneta", "Fone", "Calculadora"];
const precos = [20, 120, 5, 80, 45]; 
const etiqueta = nome => `Produto: ${nome}` ;

produtos.map(etiqueta);

const comDesconto = preco => preco * 0.9;

const caros = precos.filter(preco => preco >= 40);

const promocao = caros.map(comDesconto);

const primeiroC = produtos.find(nome => nome.startsWith("C"));

const maiusculo = produtos.map(nome => nome.toUpperCase());