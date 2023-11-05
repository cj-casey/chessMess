# chessMess
A webapp/CLI using Flask wrapped in a CUI that lets you play really bad chess.

http://vas.im:7000

It uses a Python wrapper around a C++ generated executable. If you're on edge, then switch to something else.
It's akin to a chessboard that you find in a hotel lobby.
Users can reset the board, move the pieces anywhere they want, and also transport themselves to the.....

```
 ▄▀▀▀▀▄  ▄▀▀▄ ▄▄   ▄▀▀█▄   ▄▀▀█▄▄   ▄▀▀▀▀▄   ▄▀▀▄    ▄▀▀▄      ▄▀▀▄▀▀▀▄  ▄▀▀█▄▄▄▄  ▄▀▀█▄   ▄▀▀▀▀▄      ▄▀▀▄ ▄▀▄ 
█ █   ▐ █  █   ▄▀ ▐ ▄▀ ▀▄ █ ▄▀   █ █      █ █   █    ▐  █     █   █   █ ▐  ▄▀   ▐ ▐ ▄▀ ▀▄ █    █      █  █ ▀  █ 
   ▀▄   ▐  █▄▄▄█    █▄▄▄█ ▐ █    █ █      █ ▐  █        █     ▐  █▀▀█▀    █▄▄▄▄▄    █▄▄▄█ ▐    █      ▐  █    █ 
▀▄   █     █   █   ▄▀   █   █    █ ▀▄    ▄▀   █   ▄    █       ▄▀    █    █    ▌   ▄▀   █     █         █    █  
 █▀▀▀     ▄▀  ▄▀  █   ▄▀   ▄▀▄▄▄▄▀   ▀▀▀▀      ▀▄▀ ▀▄ ▄▀      █     █    ▄▀▄▄▄▄   █   ▄▀    ▄▀▄▄▄▄▄▄▀ ▄▀   ▄▀   
 ▐       █   █    ▐   ▐   █     ▐                    ▀        ▐     ▐    █    ▐   ▐   ▐     █         █    █    
         ▐   ▐            ▐                                              ▐                  ▐         ▐    ▐    
```
Using the override button, the user can make illegal moves (not that theres any legal moves programmed), which lets them ressurrect pieces and 
permanently destroy pieces by going to the underworld!!


All thanks to Vasiliy! :D

## Webapp setup

- `python3 -m venv venv`
- `source ./venv/bin/activate`
- `pip install -r requirements.txt`
- `python3 webUI.py` should work. Good luck!

(If anyone knows why I can't get `APPLICATION_ROOT='/chessMess` to work for static content served via flask, please tell me)