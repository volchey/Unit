from elem import *

class Html(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "html", attr, content, "double")

class Head(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "head", attr, content, "double")

class Body(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "body", attr, content, "double")

class Title(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "title", attr, content, "double")

class Meta(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "meta", attr, content, "simple")

class Img(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "img", attr, content, "simple")

class Table(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "table", attr, content, "double")

class Th(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "th", attr, content, "double")

class Tr(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "tr", attr, content, "double")

class Td(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "td", attr, content, "double")

class Ul(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "ul", attr, content, "double")

class Ol(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "ol", attr, content, "double")

class Li(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "li", attr, content, "double")

class H1(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "h1", attr, content, "double")

class H2(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "h2", attr, content, "double")

class P(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "p", attr, content, "double")

class Div(Elem):
    def __init__( self, content=None, attr={}):
        Elem.__init__(self, "div", attr, content, "double")

class Span(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "span", attr, content, "simple")

class Hr(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "hr", attr, content, "double")

class Br(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "br", attr, content, "simple")

def test():
    assert str(Body([P()])) == '<body>\n  <p></p>\n</body>'
    assert str(Div([Span()])) == '<div>\n  <span />\n</div>'
    assert str(Body([H2([Text("Sometimes...")]),
                      P([Text("""She said Sometimes
You 're asking yourself why
You feel you can't get by
You feel you 're crawling on your knees
""")])])) == """<body>
  <h2>
    Sometimes...
  </h2>
  <p>
    She said Sometimes
    <br />
    You 're asking yourself why
    <br />
    You feel you can't get by
    <br />
    You feel you 're crawling on your knees
    <br />
    
  </p>
</body>"""
    print("Tests ok"+ "\n")

if __name__ == '__main__':
    test()
    print(Html([Head([Title([Text("Hello ground!")])]),
                Body([H1([Text("Oh no, not again!")]),
                      Img([], {"src":"http://i.imgur.com/pfp3T.jpg"})])]))

