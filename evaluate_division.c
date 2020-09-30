/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_division.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 11:03:30 by rpunet            #+#    #+#             */
/*   Updated: 2020/09/19 19:36:31 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct  s_graph
{
    int     nodes_size;
    char    node[40][6];
    double  map[40][40];
}               t_graph;

void    edges(t_graph *graph)
{
    int i;
    int j;
    int k;
    
    i = 0;
    while (i < graph->nodes_size)
    {
        j = 0;
        while (j < graph->nodes_size)
        {
            k = 0;
            while (k < graph->nodes_size)
            {
                if(graph->map[j][k] == -1 && graph->map[i][k] != -1 && graph->map[j][i] != -1)
                   graph->map[j][k] = graph->map[i][k] * graph->map[j][i];
                k++;
            }
            j++;
        }
        i++;
    }
}

int     nodes(t_graph *graph, char *equation)
{
    int i;
    i = 0;
    
    while (i < graph->nodes_size)
    {
        if (strcmp(graph->node[i], equation) == 0)
            return (i);
        i++;
    }
    strcpy(graph->node[i], equation);
    graph->nodes_size += 1;
    return (graph->nodes_size - 1);    
}

void    create_graph(t_graph *graph, char ***equations, int equationsSize, double *values)
{
    int i;
    int j;
    int ind_0;
    int ind_1;
    
    i = 0;
    while(i < 40)
    {
        j = 0;
        while(j < 40)
        {
            graph->map[i][j] = -1;
            j++;
        }
        i++;
    }
    i = 0;
    while (i < equationsSize)
    {
        ind_0 = nodes(graph, equations[i][0]);
        ind_1 = nodes(graph, equations[i][1]);
        graph->map[ind_0][ind_1] = values[i];
        graph->map[ind_1][ind_0] = 1 / values[i];
        i++;
    }
    edges(graph);
}

double     get_answer(t_graph *graph, char *query_0, char *query_1)
{
    int ret_0;
    int ret_1;
    
    ret_0 = nodes(graph, query_0);
    ret_1 = nodes(graph, query_1);
    return (graph->map[ret_0][ret_1]);
}
double* calcEquation(char *** equations, int equationsSize, int* equationsColSize, double* values, int valuesSize, char *** queries, int queriesSize, int* queriesColSize, int* returnSize)
{
    t_graph graph;
    int     i;
    double  *ret;
   
    ret = malloc(sizeof(double) * queriesSize);
    create_graph(&graph, equations, equationsSize, values);
    *returnSize = queriesSize;
    i = 0;
    while (i < queriesSize)
    {
        ret[i] = get_answer(&graph, queries[i][0], queries[i][1]);
        i++;
    }
    return (ret);
}
