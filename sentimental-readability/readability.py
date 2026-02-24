from cs50 import get_string
 # Solicitar el texto al usuario
text = get_string("Text: ")


# Inicializar contadores
letters = 0
words = 1
sentences = 0

# Recorrer cada carácter del texto
for c in text:
    if c.isalpha():
        letters += 1
    elif c == ' ':
        words += 1
    elif c in ['.', '!', '?']:
        sentences += 1

# Calcular promedios por 100 palabras
L = letters / words * 100
S = sentences / words * 100

# Aplicar fórmula de Coleman-Liau
index = round(0.0588 * L - 0.296 * S - 15.8)

# Mostrar el resultado de forma legible
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
