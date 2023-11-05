import subprocess
import click

@click.group()
def cli():
    'A meessee of cheesee... help... help pleessee'
    pass

@cli.command()
@click.option('--show', is_flag=True, help='Show option')
@click.option('--mv', nargs=2, type=(str, str), help='Move from <from> to <to>')
@click.option('--reset', is_flag=True, help='Resets Board')
@click.option('--override', is_flag=True, help='Override option')
def chessmess(show, mv, reset, override):
    """Let me help you out real quick
    First, the coordinates, they have no letters yet,
    the first digit is the vertical, starting from the top (0)
    to the bottom (7). The second digit is horizontal 0 to 7 ... or
    beyond that, the shadow realm. Ok. that's it. I hope you win.
    
    P.S. Honor system, this chess relies on it. Be cool man."""
    cmd = ['./chessMess']
    
    if show:
        cmd.append('--show')
    if mv:
        cmd.extend(['--mv', *mv])
    if reset:
        cmd.append('--reset')
    if override:
        cmd.append('--override')

    # Run the command and capture output
    result = subprocess.check_output(cmd).decode('utf-8')


    # Output the result
    click.echo(result)

if __name__ == '__main__':
    cli()

