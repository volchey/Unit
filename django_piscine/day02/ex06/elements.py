from elem import *

class Html(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "html", attr, content, "double")

    def is_valid(self):

        if (len(self.content) == 2 and
                self.content[0].tag == "head" and
                self.content[1].tag == "body"):
            return True
        else:
            return False

class Head(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "head", attr, content, "double")

    def is_valid(self):

        if (len(self.content) == 1 and
                self.content[0].tag == "title"):
            return True
        else:
            return False

class Body(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "body", attr, content, "double")

    def is_valid(self):
        types = ["h1", "h2", "div", "table", "ul", "ol", "span", "ou"]
        for elem in self.content:
            if elem.tag not in types:
                return False

        return True

class Title(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "title", attr, content, "double")

    def is_valid(self):
        if (len(self.content) == 0):
            return False
        if (type(self.content[0]) == Text):
            return True
        else:
            return False

class Meta(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "meta", attr, content, "simple")

class Img(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "img", attr, content, "simple")

    def is_valid(self):
        return True

class Table(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "table", attr, content, "double")

    def is_valid(self):

        if self.content[1:] != self.content[:-1] and self.content[0].tag == 'tr':
            return False
        return True

class Th(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "th", attr, content, "double")

    def is_valid(self):
        if (len(self.content) != 1):
            return False
        if (type(self.content[0]) == Text):
            return True
        else:
            return False

class Tr(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "tr", attr, content, "double")

    def is_valid(self):

        if (len(self.content) == 0):
            return False

        th_count = 0
        td_count = 0

        for elem in self.content:
            if (type(elem) == Text):
                return False

            if (elem.tag == "th"):
                th_count += 1
            if (elem.tag == "td"):
                td_count += 1

        if (th_count == 0 and td_count == 0):
            return False

        if (th_count == len(self.content) or td_count == len(self.content)):
            return True
        else:
            return False


class Td(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "td", attr, content, "double")

    def is_valid(self):
        if (type(self.content) == Text):
            return True
        else:
            return False

class Ul(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "ul", attr, content, "double")

    def is_valid(self):
        if len(self.content) == 0:
            return False

        if self.content[1:] != self.content[:-1] and self.content[0].tag == 'li':
            return False
        return True

class Ol(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "ol", attr, content, "double")

    def is_valid(self):
        if len(self.content) == 0:
            return False

        if self.content[1:] != self.content[:-1] and self.content[0].tag == 'li':
            return False
        return True

class Li(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "li", attr, content, "double")

    def is_valid(self):
        if (type(self.content) == Text):
            return True
        else:
            return False

class H1(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "h1", attr, content, "double")

    def is_valid(self):
        if (type(self.content[0]) == Text):
            return True
        else:
            return False

class H2(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "h2", attr, content, "double")

    def is_valid(self):
        if (type(self.content) == Text):
            return True
        else:
            return False

class P(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "p", attr, content, "double")

    def is_valid(self):
        if (type(self.content) == Text):
            return True
        else:
            return False

class Div(Elem):
    def __init__( self, content=None, attr={}):
        Elem.__init__(self, "div", attr, content, "double")

class Span(Elem):
    def __init__(self, content=None, attr={}):
        Elem.__init__(self, "span", attr, content, "simple")

    def is_valid(self):
        if (type(self.content) == Text or self.content.tag == 'p'):
            return True
        else:
            return False

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

