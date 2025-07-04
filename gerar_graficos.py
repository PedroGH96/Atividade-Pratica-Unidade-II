import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

df = pd.read_csv("metricas_ordenacao.csv")


df["Tipo_Algoritmo"] = df["Algoritmo"].apply(lambda x: "O(N^2)" if any(algo in x for algo in ["OrdenacaoBolha", "OrdenacaoInsercao", "OrdenacaoSelecao"]) else "O(N log N)")
df["Nome_Algoritmo"] = df["Algoritmo"].apply(lambda x: x.split("_")[0])
df["Tipo_Dado"] = df["Algoritmo"].apply(lambda x: x.split("_")[1])


plt.figure(figsize=(15, 10))
sns.lineplot(data=df, x="Tamanho", y="Tempo_ms", hue="Nome_Algoritmo", style="Tipo_Dado", marker="o")
plt.title("Tempo de Execução vs. Tamanho do Vetor")
plt.xlabel("Tamanho do Vetor")
plt.ylabel("Tempo (ms)")
plt.xscale("log")
plt.yscale("log")
plt.grid(True, which="both", ls="--", c="0.7")
plt.legend(title="Algoritmo e Tipo de Dado")
plt.tight_layout()
plt.savefig("tempo_vs_tamanho.png")
plt.close()


plt.figure(figsize=(15, 10))
sns.lineplot(data=df, x="Tamanho", y="Comparacoes", hue="Nome_Algoritmo", style="Tipo_Dado", marker="o")
plt.title("Comparações vs. Tamanho do Vetor")
plt.xlabel("Tamanho do Vetor")
plt.ylabel("Número de Comparações")
plt.xscale("log")
plt.yscale("log")
plt.grid(True, which="both", ls="--", c="0.7")
plt.legend(title="Algoritmo e Tipo de Dado")
plt.tight_layout()
plt.savefig("comparacoes_vs_tamanho.png")
plt.close()


plt.figure(figsize=(15, 10))
sns.lineplot(data=df, x="Tamanho", y="Trocas", hue="Nome_Algoritmo", style="Tipo_Dado", marker="o")
plt.title("Trocas vs. Tamanho do Vetor")
plt.xlabel("Tamanho do Vetor")
plt.ylabel("Número de Trocas")
plt.xscale("log")
plt.yscale("log")
plt.grid(True, which="both", ls="--", c="0.7")
plt.legend(title="Algoritmo e Tipo de Dado")
plt.tight_layout()
plt.savefig("trocas_vs_tamanho.png")
plt.close()

print("Gráficos gerados com sucesso: tempo_vs_tamanho.png, comparacoes_vs_tamanho.png, trocas_vs_tamanho.png")


summary_df = df.groupby(["Nome_Algoritmo", "Tipo_Dado"]).agg({
    "Tempo_ms": "mean",
    "Comparacoes": "mean",
    "Trocas": "mean"
}).reset_index()

print("\nTabela Comparativa de Métricas Médias:")
print(summary_df.to_markdown(index=False))

with open("tabela_comparativa.md", "w") as f:
    f.write("# Tabela Comparativa de Métricas Médias\n\n")
    f.write(summary_df.to_markdown(index=False))

print("Tabela comparativa salva em tabela_comparativa.md")

