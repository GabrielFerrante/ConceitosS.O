#################################################################################
#    Grupo 1 - SSC5723 - 1/2021                                                 #
#    Script auxiliar para leitura e parsing dos arquivos de saída do strace.    #
#################################################################################

import re
import os
from tabulate import tabulate

'''
    Listar todos os arquivos de um diretório.
'''
def getListOfFiles(dirName):

    listOfFile = os.listdir(dirName)
    allFiles = list()

    for entry in listOfFile:
        fullPath = os.path.join(dirName, entry)
        if os.path.isdir(fullPath):
            allFiles = allFiles + getListOfFiles(fullPath)
        else:
            allFiles.append(fullPath)
                
    return allFiles 

'''
    Lê o diretório de logs do strace e faz o parsing das chamadas e tempos de execução
'''
def main():

    calls = []
    
    print("# Chamadas de sistema e tempos de execução\n")

    print("## Tempo das chamadas")

    headers = ["Chamada de sistema", "Tempo de execução (µs)"]

    dir_strace_logs = './output/strace/'

    listOfFiles = getListOfFiles(dir_strace_logs)
    
    listOfFiles = list()
    for (dirpath, _, filenames) in os.walk(dir_strace_logs):
        listOfFiles += [os.path.join(dirpath, file) for file in filenames]
        
            
    for log in listOfFiles:
        print("\n### Arquivo: {}\n".format(log))
        # Parsing de cada arquivo individualmente
        saida_tratada = ler_saida_strace(log)

        # Salvando todas as chamadas
        calls.extend([i[0] for i in saida_tratada])   
        
        print(tabulate(saida_tratada, headers, tablefmt="github"))

    print("\n## Descrição das chamadas\n")

    # Chamadas únicas
    chamadasUnicas = list(set(calls))
    chamadasUnicas.sort()

    headers_desc = ["Chamada de sistema", "Descrição"]
    print(tabulate([(i, '') for i in chamadasUnicas], headers_desc, tablefmt="github"))

'''
    Parsing do arquivo do strace
'''
def ler_saida_strace(filename):
    resultado = []

    with open(filename) as f:
        content = f.readlines()

    for call in content:
        parseCall = re.search(r'(\d*\.\d*)\s(\w+)\(', call, re.M)

        if parseCall:
            horario = parseCall.group(1)
            syscall = parseCall.group(2) + '()'
        
        parseTempoGasto = re.search(r'<(\d+\.\d*)>', call, re.M)

        if parseTempoGasto:
            tempo_gasto = parseTempoGasto.group(1)
            tempo_gasto = int(float(tempo_gasto) * 10 ** 6) # Convertendo de segundos para microsegundos
        
        #print('{},{},{},{}'.format(filename,horario,syscall,tempo_gasto))
        resultado.append([syscall, tempo_gasto])
        
    return resultado


if __name__ == '__main__':
    main()