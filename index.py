import serial
import os
import time

os.system('cls')

# Configurações da porta serial
porta_serial = 'COM4'  # Porta serial no Windows
baud_rate = 9600

# Inicializa a comunicação serial
arduino = serial.Serial(porta_serial, baud_rate)
time.sleep(2)  # Aguarda a inicialização da porta serial

while True:
    # Solicita ao usuário que digite uma opção
    opcao = input("Digite 'vidro', 'lata', 'plastico' ou 'sair' para sair: ").strip().lower()

    # Verifica se o usuário deseja sair
    if opcao == 'sair':
        print("Saindo...")
        arduino.write(opcao.encode())  # Envie 'x' para o Arduino
        time.sleep(5)
        break

    # Verifica se a opção é válida e envia para o Arduino
    if opcao in ['vidro', 'lata', 'plastico']:
        arduino.write(opcao.encode())  # Envie a opção para o Arduino
    else:
        print("Opção inválida!")

# Fecha a comunicação serial
arduino.close()
