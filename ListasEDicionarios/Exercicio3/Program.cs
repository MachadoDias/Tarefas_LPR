Console.WriteLine("Digite a quantidade de pessoas:");
int x = Convert.ToInt32(Console.ReadLine());
Dictionary<string, int> pessoas = new Dictionary<string, int>();
int media = 0;
(string nome, int idade) pessoaMaisNova = ("", int.MaxValue), pessoaMaisVelha = ("", int.MinValue);
for (int i = 0; i < x; i++)
{
    Console.WriteLine($"Digite o nome da pessoa {i + 1}:");
    string nome = Console.ReadLine();
    Console.WriteLine($"Digite a idade de {nome}:");
    int idade = Convert.ToInt32(Console.ReadLine());
    pessoas.Add(nome, idade);
    media += idade;
    if (idade < pessoaMaisNova.idade)
    {
        pessoaMaisNova.nome = nome; pessoaMaisNova.idade = idade;
    }
    if (idade > pessoaMaisVelha.idade)
    {
        pessoaMaisVelha.nome = nome; pessoaMaisVelha.idade = idade;
    }
}
media /= x;
Console.WriteLine($"Média: {media}");
foreach (var pessoa in pessoas)
{
    if (pessoa.Value > media) Console.WriteLine($"{pessoa.Key} : {pessoa.Value}");
}
Console.WriteLine($"Pessoa mais velha: {pessoaMaisVelha.nome} \nPessoa mais nova: {pessoaMaisNova.nome}");
Console.WriteLine("Digite uma idade para remover pessoas com essa idade:");
int y = Convert.ToInt32(Console.ReadLine());
foreach (var pessoa in pessoas.ToList())
{
    if (pessoa.Value == y) pessoas.Remove(pessoa.Key);
    else Console.WriteLine($"{pessoa.Key} : {pessoa.Value}");
}
