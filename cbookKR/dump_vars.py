import gdb

gdb.execute('file test')
gdb.execute('break 15')
gdb.execute('run')

frame = gdb.selected_frame()
for sym in frame.block():
        if sym.is_variable:
                    print(sym.name, gdb.parse_and_eval(f'&{sym.name}'), sym.value(frame))
gdb.execute('s')
gdb.execute('info args')
