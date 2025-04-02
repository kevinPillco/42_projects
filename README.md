sequenceDiagram
    participant U as Usuario
    participant F as Frontend
    participant A as API
    participant C as Core
    participant R as Retrieval
    participant V as Vector_Store
    participant L as LLM
    participant M as Milvus

    U->>F: Envía mensaje
    F->>A: POST /chat
    A->>C: Ejecutar lógica
    C->>R: Buscar contexto
    R->>V: Buscar vectores
    V->>M: Consulta Milvus
    M-->>V: Resultados
    V-->>R: Vecinos cercanos
    R-->>C: Contexto relevante

    C->>L: HyDE (opcional)
    L-->>C: Hipótesis generada

    C->>L: Prompt + Contexto
    L-->>C: Respuesta generada

    C->>A: Respuesta final
    A->>F: JSON con respuesta
    F->>U: Muestra mensaje del bot
