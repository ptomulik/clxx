import os
import tarfile
import io

try:
    # Python 3
    from urllib.request import urlopen, urlretrieve
except ImportError:
    # Python 2
    from urllib import urlopen, urlretrieve

def untar(tar, **kw):
    # Options
    try:                strip_components = kw['strip_components']
    except KeyError:    strip_components = 0
    try:                path = kw['path']
    except KeyError:    path = '.'
    # Download the tar file
    members = [m for m in tar.getmembers() if len(m.name.split(os.sep)) > strip_components]
    if strip_components > 0:
        for m in members:
            m.name = os.path.join(*(m.name.split(os.sep)[strip_components:]))
    tar.extractall(path = path, members = members)

def urluntar(url, **kw):
    # Download the tar file
    tar = tarfile.open(fileobj = io.BytesIO(urlopen(url).read()))
    untar(tar, **kw)
    tar.close()
