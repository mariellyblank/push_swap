#include "push_swap.h"

void	a_to_b(t_mem *a, t_mem *b, int chunk_start, int chunk_done)
{
	int	count;

	while (a->size > chunk_start)
	{
		count = 0;
		while (count < chunk_start)
		{
			// Rotate `a` until the first element is larger than the current chunk
			while (a->sorted[0] > chunk_start * chunk_done)
				rotate(a);
			// If the first element of `a` is smaller than half the current chunk
			if (a->sorted[0] < chunk_start * chunk_done - (chunk_start / 2))
				push(a, b);
			// If `a` is larger than half the current chunk
			else
			{
				push(a, b);
				if (b->size > 1)
					rotate(b);
			}
			count++;
		}
		chunk_done = chunk_done + 1;
	}
}

void	b_to_a(t_mem *a, t_mem *b)
{
	int	i;

	while (a->size != 0)
		push(a, b);
	while (b->size != 0)
	{
		i = max_index(b);
		if (i <= b->size / 2)
		{
			while (i > 0)
			{
				rotate(b);
				i--;
			}
		}
		else
		{
			while (i < b->size)
			{
				reverse_rotate(b);
				i++;
			}
		}
		push(b, a);
	}
}

void	algo_algo(t_mem *a, t_mem *b)
{
	int	chunk_start;
	int	chunk_done;

	chunk_done = 1;
	if (a->size <= 100)
		chunk_start = 20;
	else
		chunk_start = 70;
	a_to_b(a, b, chunk_start, chunk_done);
	b_to_a(a, b);
}
