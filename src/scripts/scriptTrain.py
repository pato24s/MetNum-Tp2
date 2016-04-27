import csv
from sets import Set #importa conjuntos

input_path = '../../data/train.csv'
output_path = '../../data/train.dat'

	# score_reader = csv.reader(csvfile,delimiter=',',skipinitialspace=True)
	# # Skip the header
	# next(score_reader, None)
	# teams = Set() #conjunto vacio
	# n_games = 0
	# # String with info of the games.
	# out_str = ''
	# for row in score_reader:
	# 	teams.add(row[7])
	# 	teams.add(row[17])
	# 	n_games = n_games+1
	# 	out_str = out_str + row[5] + ' ' + row[7] + ' ' + '1' + ' ' + row[17] + ' ' + '0' + '\n'
	# # Write number of teams and games
	# outfile.write(str(len(teams)) + ' ' + str(n_games) + '\n')
	# # Write games details
	# outfile.write(out_str)
with open(input_path,'rb') as csvfile,open(output_path,'w') as outfile:
	it = csv.reader(csvfile)
	next(it, None)
	#pixeles = Set()
	#out_str = ''
	out_str = ''
	#for row in it 
	for row in it:
		outfile.write(row[0] + '_')
		for i in xrange(1,785):
			out_str = row[i] + ' ' 
			outfile.write(out_str)
		outfile.write('/'+'\n')
