static void cadastrarHeroi(ref string nome, ref string poder, ref byte pontuacao){
    Console.Write("Digite o nome do heroí: ");
    nome = Console.ReadLine();
    Console.Write("Digite o poder do heroí: ");
    poder = Console.ReadLine();
    
    for(;;){
        Console.Write("Digite a pontuação do heroí, de 1 a 100: ");
        if(byte.TryParse(Console.ReadLine(), out pontuacao) && pontuacao >= 1 && pontuacao <= 100) break;
        Console.WriteLine("Valor invalído");
    }
}

static void selecionarEquipe(string n1, string n2, string n3, string n4, string n5, string p1, string p2, string p3, string p4, string p5, byte s1, byte s2, byte s3, byte s4, byte s5, ref byte escolhido1, ref byte escolhido2, ref byte escolhido3){
    Console.WriteLine($"Escolha 3 heroís por número\n1 - {n1}\n2 - {n2}\n3 - {n3}\n4 - {n4}\n5 - {n5}");
    escolhido1 = Convert.ToByte(Console.ReadLine());
    escolhido2 = Convert.ToByte(Console.ReadLine());
    escolhido3 = Convert.ToByte(Console.ReadLine());
}

static int calcularPontuacaoTotal(int escolhido1, int escolhido2, int escolhido3, byte s1, byte s2, byte s3, byte s4, byte s5){
    return pontuacaoPorNumero(escolhido1, s1, s2, s3, s4, s5) + pontuacaoPorNumero(escolhido2, s1, s2, s3, s4, s5) + pontuacaoPorNumero(escolhido3, s1, s2, s3, s4, s5);
}

static void exibirEquipe(int escolhido1, int escolhido2, int escolhido3, string n1, string n2, string n3, string n4, string n5, string p1, string p2, string p3, string p4, string p5, byte s1, byte s2, byte s3, byte s4, byte s5){
    Console.WriteLine($"1 - {dadoPorNumero(escolhido1, n1, n2, n3, n4, n5)} {dadoPorNumero(escolhido1, p1, p2, p3, p4, p5)}");
    Console.WriteLine($"2 - {dadoPorNumero(escolhido2, n1, n2, n3, n4, n5)} {dadoPorNumero(escolhido2, p1, p2, p3, p4, p5)}");
    Console.WriteLine($"3 - {dadoPorNumero(escolhido3, n1, n2, n3, n4, n5)} {dadoPorNumero(escolhido3, p1, p2, p3, p4, p5)} ");
    Console.WriteLine($"Pontuação da equipe: {calcularPontuacaoTotal(escolhido1, escolhido2, escolhido3, s1, s2, s3, s4, s5)}");
}

static void menuPrincipal(){
    string n1 = "", n2 = "", n3 = "", n4 = "", n5 = "";
    string p1 = "", p2 = "", p3 = "", p4 = "", p5 = "";
    byte s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0;
    byte escolhido1 = 0, escolhido2 = 0, escolhido3 = 0;
    while(true){
        Console.WriteLine("Menu\n1 - Cadastrar herois\n2 - Formar equipe\n3 - Exibir equipe\n4 - Sair");
        int escolha = Convert.ToInt16(Console.ReadLine());
        switch(escolha){
            case 1:
            cadastrarHeroi(ref n1, ref p1, ref s1);
            cadastrarHeroi(ref n2, ref p2, ref s2);
            cadastrarHeroi(ref n3, ref p3, ref s3);
            cadastrarHeroi(ref n4, ref p4, ref s4);
            cadastrarHeroi(ref n5, ref p5, ref s5);
            break;
            case 2:
            selecionarEquipe(n1, n2, n3, n4, n5, p1, p2, p3, p4, p5, s1, s2, s3, s4, s5, ref escolhido1, ref escolhido2, ref escolhido3);
            break;
            case 3:
            exibirEquipe(escolhido1, escolhido2, escolhido3, n1, n2, n3, n4, n5, p1, p2, p3, p4, p5, s1, s2, s3, s4, s5);
            break;
            case 4:
            return;
            default:
            Console.WriteLine("Escolha Invalída");
            break;
        }
    } 
    
}

static string dadoPorNumero(int escolha, string n1,string n2, string n3, string n4, string n5){
    switch (escolha){
        case 1: return n1;
        case 2: return n2;
        case 3: return n3;
        case 4: return n4;
        case 5: return n5;
        default: return "";
    }
}
static byte pontuacaoPorNumero(int escolha, byte n1,byte n2, byte n3, byte n4, byte n5){
    switch (escolha){
        case 1: return n1;
        case 2: return n2;
        case 3: return n3;
        case 4: return n4;
        case 5: return n5;
        default: return 0;
    }
}

menuPrincipal();