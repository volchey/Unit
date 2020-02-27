from elements import *

types = ["html", "head", "body", "title",
         "meta", "img", "table", "th", "tr",
         "td", "ul", "ol", "li", "h1", "h2",
         "p", "div", "span", "hr", "br"]

class Page():
    def __init__(self, elem: Elem):
        self.elem = elem

    def is_valid(self):

        if (type(self.elem) == Text):
            return True

        for sub_elem in self.elem.content:
            if not Page(sub_elem).is_valid():
                return False

        if self.elem.tag in types:
            return self.elem.is_valid()
        else:
            return False

    def __str__(self):
        if (type(self.elem) == Text):
            return self.elem

        for sub_elem in self.elem.content:
            Page(sub_elem).__str__()

        if self.elem.tag == "html":
            return "<!DOCTYPE html>\n" + self.elem.__str__()
        else:
            return self.elem.__str__()

    def write_to_file(self, filename):
        f = open(filename + '.html', 'w')
        f.write(self.__str__())
        f.close()

if __name__ == '__main__':
    a = Page(H1([P()]))
    print(a)
    b = Page(Body([Title()]))
    print("Body->Title: "+str(b.is_valid()))
    r = Page(Html([Head(), Body()]))
    print(r)
    print("Html->[Head, Body]: "+ str(r.is_valid()))

    c = Page(Span([H1([Img()])]))
    print("Span->H1: " + str(c.is_valid()))

    d = Page(Tr([Li()]))
    print("Tr->Li: "+str(d.is_valid()))

    e = Page(Tr([Th([Text("ololo")])]))
    print(e)
    print("Tr->Th: " + str(e.is_valid()))

    f = Page(Tr())
    print("Tr: " + str(f.is_valid()))

    big_html = Html([Head([Title([Text("Hello ground!")])]),
                Body([H1([Text("Oh no, not again!")])])])
    big_page = Page(big_html)
    print("big_page: " + str(big_page.is_valid()))
    big_page.write_to_file("Great recursion")


    table = Page(Table([Tr([Text("ololo")])]))
    print("Table: " + str(table.is_valid()))

    # a =
    # print(a)

