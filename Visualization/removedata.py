with open(r"main_animation.py", "r") as program:
    code = program.read()

with open(r"data.txt", "r") as f:
    snippet = f.read()

new_code = code.replace(
    f"# Data_S\n{snippet}\n# Data_E",
    "# Data_S\n# Data_E"
)

with open(r"main_animation.py", "w") as program:
    program.write(new_code)