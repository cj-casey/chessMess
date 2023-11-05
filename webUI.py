from click_web import create_click_web_app
import pythonClickWrapper

#class PrefixMiddleware(object):
#
#    def __init__(self, app, prefix=''):
#        self.app = app
#        self.prefix = prefix
#
#    def __call__(self, environ, start_response):
#
#        if environ['PATH_INFO'].startswith(self.prefix):
#            environ['PATH_INFO'] = environ['PATH_INFO'][len(self.prefix):]
#            environ['SCRIPT_NAME'] = self.prefix
#            return self.app(environ, start_response)
#        else:
#            start_response('404', [('Content-Type', 'text/plain')])
#            return ["This url does not belong to the app.".encode()]

app = create_click_web_app(pythonClickWrapper, pythonClickWrapper.cli)
#app.config['SCRIPT_NAME'] = '/chessMess'
#app.config['APPLICATION_ROOT'] = '/chessMess'
#app.wsgi_app = PrefixMiddleware(app.wsgi_app, prefix='/chessMess')

if __name__ == '__main__':
        #app.run(host='127.0.0.1', port=7000)
        app.run(host='0.0.0.0', port=7000)

