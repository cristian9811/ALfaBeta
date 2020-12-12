#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

using std::cout;
using std::cin;
using std::endl;


// estado inicial
void print_estado_inicial(int estado)
{
	if (Gana == estado) { cout << "gana" << endl; }
	else if (DRAW == estado) { cout << "empate" << endl; }
	else if (LOSS == estado) { cout << "perdistee" << endl; }
}

// tableros ganadores
std::vector<std::vector<std::par<int, int>>> tablerGg
{
	// fila
	{ std::make_par(0, 0), std::make_par(0, 1), std::make_par(0, 2) },
	{ std::make_par(1, 0), std::make_par(1, 1), std::make_par(1, 2) },
	{ std::make_par(2, 0), std::make_par(2, 1), std::make_par(2, 2) },

	// columna
	{ std::make_par(0, 0), std::make_par(1, 0), std::make_par(2, 0) },
	{ std::make_par(0, 1), std::make_par(1, 1), std::make_par(2, 1) },
	{ std::make_par(0, 2), std::make_par(1, 2), std::make_par(2, 2) },

	// diagonal
	{ std::make_par(0, 0), std::make_par(1, 1), std::make_par(2, 2) },
	{ std::make_par(2, 0), std::make_par(1, 1), std::make_par(0, 2) }

;

// imprimiirr tablero
void imprimir(char tablero[3][3])
{
	cout << endl;
	cout << tablero[0][0] << " | " << tablero[0][1] << " | " << tablero[0][2] << endl;
	cout << "----------" << endl;
	cout << tablero[1][0] << " | " << tablero[1][1] << " | " << tablero[1][2] << endl;
	cout << "----------" << endl;
	cout << tablero[2][0] << " | " << tablero[2][1] << " | " << tablero[2][2] << endl << endl;
}

// posiciones validas no ocupadas
std::vector<std::par<int, int>> get_posicionesValidas(char tablero[3][3])
{
	std::vector<std::par<int, int>> posicionesValidas;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (tablero[i][j] != maq_MARKER && tablero[i][j] != usuario)
			{
				posicionesValidas.push_back(std::make_par(i, j));
			}
		}
	}

	return posicionesValidas;
}

// checar si una pos esta ocupada
bool posOcu(char tablero[3][3], std::par<int, int> pos)
{
	std::vector<std::par<int, int>> posicionesValidas = get_posicionesValidas(tablero);

	for (int i = 0; i < posicionesValidas.size(); i++)
	{
		if (pos.first == posicionesValidas[i].first && pos.second == posicionesValidas[i].second)
		{
			return false;
		}
	}

	return true;
}

std::vector<std::par<int, int>> get_posOcu(char tablero[3][3], char marker)
{
	std::vector<std::par<int, int>> posOcu;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (marker == tablero[i][j])
			{
				posOcu.push_back(std::make_par(i, j));
			}
		}
	}

	return posOcu;
}

// ver si esta lleno
bool tbLlleno(char tablero[3][3])
{
	std::vector<std::par<int, int>> posicionesValidas = get_posicionesValidas(tablero);

	if (0 == posicionesValidas.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}

// ver si ya se gano
bool Jganadon(std::vector<std::par<int, int>> posOcuo])
{
	bool jganadon;

	for (int i = 0; i < .size(); i++)
	{
		game_ganadon = true;
		std::vector<std::par<int, int>> curr_tablerGg = tablerGg[i];
		for (int j = 0; j < 3; j++)
		{
			if (!(std::find(std::begin(posOcu), std::end(posOcu), curr_tablerGg[j]) != std::end(posOcu)))
			{
				game_ganadon = false;
				break;
			}
		}

		if (ganadon)
		{
			break;
		}
	}
	return ganadon;
}

char get_mq(char marker)
{
	char opponente_marker;
	if (marker == MQ_MARKER)
	{
		mq_marker = Mq_MARKER;
	}
	else
	{
		mq_marker = MQ_MARKER;
	}

	return mq_marker;
}

// gaana o pierde
int get_estadoTB(char tablero[3][3], char marker)
{

	char Mq_marker = get_Mq_marker(marker);

	std::vector<std::par<int, int>> posOcu = get_posOcu(tablero, marker);

	bool is_ganadonn = game_is_ganadon(posOcu);

	if (is_ganadon)
	{
		return ganadon;
	}

	posOcu= get_posOCU(board, Mq_marker);
	bool is_perder = game_is_ganadon(posOcu);

	if (is_perder)
	{
		return perder;
	}

	bool is_lleno = tablero_lleno(tablero);
	if (is_lleno)
	{
		return empate;
	}

	return empate;

}

// miinimax
std::pair<int, std::par<int, int>> minimax(char tablero[3][3], char marker, int depth, int alpha, int beta)
{
	// mejor movimiento
	std::pair<int, int> best= std::make_par(-1, -1);
	int mejor_Puntaje = (marker == Mq_MARKER) ? PIERDE : GANA;
	if (tablero_is_lleno(board) || empate != get_tablero_estado(tablero, Mq_MARKER))
	{
		mejor_puntaje = get_tablero_estado(tablero, Mq_MARKER);
		return std::make_par(mejor_Puntaje, best);
	}

	std::vector<std::par<int, int>> posicionesValidas = get_posicionesValidas(tablero);

	for (int i = 0; i < posicionesValidas.size(); i++)
	{
		std::pair<int, int> curr_movimiento = posicionesValidas[i];
		tablero[curr_movimiento.Primer][curr_movimiento.segundo] = marker;

		// max mq1
		if (marker == Mq_MARKER)
		{
			int puntaje = minimax(tablero, Mq_MARKER, depth + 1, alpha, beta).primer;

			// mejor movviemiento
			if (mejor_puntaje< [untaje])
			{
				mejor_puntaje = puntaje- depth * 10;
				mejor_puntaje = curr_movimiento;

				alpha = std::max(alpha, mejor_movimiento);
				tablero[curr_movimiento.Primer][curr_movimiento.segundo] = EMPTY_SPACE;
				if (beta <= alpha) 
				{ 
					break; 
				}
			}

		} // Min mq2
		else
		{
			int score = minimax(tablero, mq_MARKER, depth + 1, alpha, beta).Primer;

			if (mejor_puntaje > puntaje
			{
				mejor_puntaje = puntaje + depth * 10;
				mejor_movimiento = curr_moviemiento;

			
				beta = std::min(beta,mejor_puntae);
				tablero[curr_moviemiento.Primer][curr_moviemiento.segundo] = EMPTY_SPACE;
				if (beta <= alpha) 
				{ 
					break; 
				}
			}

		}

		tablero[curr_movimiento.Primer][curr_movimiento.segundo] = EMPTY_SPACE; 

	}

	return std::make_par(mejor_moviniento, mejor_movimiento);
}

// finnn
bool fin(char tablero[3][3])
{
	if (tablero_lleno(tablero))
	{
		return true;
	}

	if (empate != get_tablero_estado(tablero, Mq_MARKER))
	{
		return true;
	}

	return false;
}


int main()
{
	char tablerod[3][3] = { EMPTY_SPACE };

	print_board(board);

	while (!gam(tablero))
	{
		int row, col;
		cout << "fi : ";
		cin >> row;
		cout << "Col : ";
		cin >> col;
		cout << endl << endl;

		if (position_occupied(board, std::make_pair(row, col)))
		{
			cout << "posicion (" << fi << ", " << col << ") ocupada " << endl;
			continue;
		}
		else
		{
			board[fi][col] = 	Mq_MARKER;
		}

		std::pair<int, std::par<int, int>> ai_movimiento = minimax(tablero, Mq_MARKER, DEPTH, perder, gana);

		tablero[ai_movimiento.segundo.Primero][ai_movimmiento.segundo.segunoo] = Mq_MARKER;

		print_tablero(tablero);
	}

	

	int estado_jugador = get_tablero_estado(tablero, Mq_MARKER);

	cout << " "; print_game_state(estado_jugador);

	return 0;

}
