while True:
    try:
        dollars = float(input("Change owed: "))
        if dollars >= 0:
            break
    except ValueError:
        continue  # Si el input no es un número, vuelve a pedirlo

# Convertir a centavos y redondear
cents = round(dollars * 100)

# Inicializar contador
coins = 0

# Calcular monedas de 25¢
coins += cents // 25
cents %= 25

# Calcular monedas de 10¢
coins += cents // 10
cents %= 10

# Calcular monedas de 5¢
coins += cents // 5
cents %= 5

# Calcular monedas de 1¢
coins += cents

# Imprimir total de monedas
print(coins)
