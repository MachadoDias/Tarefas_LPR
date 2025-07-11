using System.Xml;

int x = Convert.ToInt32(Console.ReadLine());
List<string> input = new List<string>();
List<List<string>> saida = new List<List<string>>();
for (int i = 0; i < x; i++)
{
    input.Add(Console.ReadLine());
}
input.Sort((x, y) => x.Length.CompareTo(y.Length));
saida.Add(new List<string> {input[0]});
for (int i = 1; i < x; i++)
{
    bool foiAdd = false;
    foreach (List<string> linha in saida)
    {
        if (input[i].Length > linha.Last().Length)
        {
            linha.Add(input[i]);
            foiAdd = true;
            break;
        }
    }
    if(!foiAdd) saida.Add(new List<string> {input[i]});
}
foreach (List<string> linha in saida)
{
    foreach (string nome in linha)
    {
        Console.Write($"{nome} ");
    }
    Console.WriteLine();
}