from torchtext.data.utils import get_tokenizer
from collections import Counter
from torchtext.vocab import Vocab
def my_tokenizer():
    tokenizer = {}
    tokenizer['de'] = get_tokenizer('spacy', language='de_core_news_sm')  # 德语
    tokenizer['en'] = get_tokenizer('spacy', language='en_core_web_sm')  # 英语
    return tokenizer


def build_vocab(tokenizer, filepath, min_freq, specials=None):
    if specials is None:
        specials = ['<unk>', '<pad>', '<bos>', '<eos>']
    counter = Counter()
    with open(filepath, encoding='utf-8') as f:
        for string_ in f:
            counter.update(tokenizer(string_))
    return Vocab(counter, specials=specials, min_freq=min_freq)


class LoadEnglishGermanDataset():
    def __init__(self, train_file_paths=None, tokenizer=None, batch_size=2, min_freq=1):
        